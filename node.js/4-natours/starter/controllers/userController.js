const User = require('../models/userModel');
const catchAsync = require('../utils/catchAsync');

// ROUTER HANDLERS
exports.getAllUsers = catchAsync(async (req, res, next) => {
  const users = await User.find();
  res.status(500).json({
    status: 'error',
    results: users.length,
    data: {
      users,
    },
  });
});

exports.getUser = (req, res) => {
  res.status(500).json({
    status: 'error',
    message: 'Route not yet defined yet',
  });
};

exports.createUser = (req, res) => {
  res.status(500).json({
    status: 'error',
    message: 'Route not yet defined yet',
  });
};

exports.updateUser = (req, res) => {
  res.status(500).json({
    status: 'error',
    message: 'Route not yet defined yet',
  });
};

exports.deleteUser = (req, res) => {
  res.status(500).json({
    status: 'error',
    message: 'Route not yet defined yet',
  });
};
