const AppError = require('../utils/appError');

// To make custom errors, deal with errors and make custom scripts for each of them,
// individually..

const handleCastErrorDB = (err) =>
  // see how what postman returns when this error occurs
  new AppError(`Invalid ${err.path}: ${err.value}`, 400);

const handleJwtError = () =>
  new AppError(`Invalid Token, please login again`, 401);

const handleDuplicateFieldsDB = (err) => {
  // see how what postman returns when this error occurs
  // this error comes in mongo:

  // extracting the value from the string
  const val = err.errormsg.match(/(["'])(\\?.)*?\1/)[0];

  const message = `ERROR -> Duplicate Field Value: ${val} `;
  return new AppError(message, 400);
};

const handleValidationErrorsDB = (err) => {
  // this will get all the errors in the message.
  const allerrors = Object.values(err.errors).map((el) => el.message);

  const message = `Invalid Input Data.\n ${allerrors.join('. ')}`;

  return new AppError(message, 400);
};

const sendErrorDev = (err, res) => {
  res.status(err.statusCode).json({
    status: err.status,
    error: err,
    message: err.message,
    stack: err.stack,
  });
};

const sendErrorProd = (err, res) => {
  // this is a standard practice
  // Operational Error
  if (err.isOperational) {
    res.status(err.statusCode).json({
      status: err.status,
      message: err.message,
    });
  }
  // Programming Error. Make sure don't leak any unecessary information to the client
  else {
    // 1) Log the error for ourself
    console.error('ERROR');
    // 2) Send a generic message
    res.status(500).json({
      status: 'Error',
      message: 'Something went wrong',
    });
  }
};
module.exports = (err, req, res, next) => {
  // this is the standard
  err.statusCode = err.statusCode || 500;
  err.status = err.status || 'error';

  if (process.env.NODE_ENV === 'dev') {
    sendErrorDev(err, res);
  } else if (process.env.NODE_ENV === 'prod') {
    let customError = { ...err };
    // lets write some meaningful errors
    // we will pass our error in this function
    // this function will use our AppError class to make the error meaningful
    if (customError.name === 'CastError') {
      customError = handleCastErrorDB(customError);
    }

    // for duplicate records in our DB
    if (customError.code === 1100)
      customError = handleDuplicateFieldsDB(customError);

    if (customError.name === 'ValidationError')
      customError = handleValidationErrorsDB(customError);

    if (customError.name === 'JsonWebTokenError')
      customError = handleJwtError();

    sendErrorProd(customError, res);
  }
};
