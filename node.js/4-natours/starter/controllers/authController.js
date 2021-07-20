const { promisify } = require('util');
const jwt = require('jsonwebtoken');
const AppError = require('../utils/appError');

const User = require('../models/userModel');
const catchAsync = require('../utils/catchAsync');

const signToken = (id) =>
  jwt.sign({ id }, process.env.JWT_SECRET, {
    expiresIn: process.env.JWT_EXPIRES_IN,
  });

exports.signup = catchAsync(async (req, res, next) => {
  const newUser = await User.create({
    name: req.body.name,
    email: req.body.email,
    password: req.body.password,
    passwordConfirm: req.body.passwordConfirm,
  });

  // here we sign and send our token
  // it takes a payout and secret key
  // also takes special options
  const token = signToken(newUser._id);
  // then we will send the token to the client
  res.status(201).json({
    status: 'success',
    token,
    data: { user: newUser },
  });
});

exports.login = catchAsync(async (req, res, next) => {
  const { email, password } = req.body;

  // 1. check email and password exist
  if (!email || !password)
    return next(new AppError('Please provide valid email and password', 400));

  // 2. check if user exists && password is correct or not
  // we have to use it like this because we selected password as false
  const user = await User.findOne({ email }).select('+password');
  // if the user doesn't exist then exit
  // if the user exists but passwords don't match
  if (!user || !(await user.correctPassword(password, user.password))) {
    return next(new AppError('Incorrect Email or Password', 401));
  }
  // 3. If everything OK -> send token to client
  const token = signToken(user._id);
  // token signing in not working
  console.log(`TOKEN SIGN: ${token}`);
  res.status(200).json({
    status: 'success',
    token,
  });
});

exports.protect = catchAsync(async (req, res, next) => {
  // 1) Get the token
  // the request.headers.authorization must have the following string:
  // "Bearer token-identifier"
  let token;
  if (
    req.headers.authorization &&
    req.headers.authorization.startsWith('Bearer')
  ) {
    token = req.headers.authorization.split(' ')[1]; // here we have our token
  }

  if (!token) {
    return next(
      new AppError('You are not logged in. Please login to get the access', 401)
    );
  }

  // 2) Verify token
  // COURSE -> Section 10. Video 09.
  const decoded = await promisify(jwt.verify)(token, process.env.JWT_SECRET);
  // 3) Check if exits
  const currentUser = await User.findById(decoded.id);
  if (!currentUser) {
    return next(new AppError('The token does no longer exist', 401));
  }
  // 4) Check if User changed password after token was issued
  // when user changes their password, they need a new token
  if (currentUser.changedPasswordAfter(decoded.iat)) {
    return next(
      new AppError(
        'User recently changed their password. Please login again',
        401
      )
    );
  }
  // Grant access to protected Route
  req.user = currentUser;
  next();
});

exports.restrictTo =
  (...roles) =>
  (req, res, next) => {
    // if the roles is not in roles array then return
    if (!roles.include(req.user.role)) {
      return next(new AppError('You do not have the permission!!', 403));
    }
    next();
  };
