class AppError extends Error {
  constructor(message, statusCode) {
    super(message); //because Error only accepts the message
    this.statusCode = statusCode;
    this.status = `${statusCode}`.startsWith('4') ? 'fail' : 'error';
    this.isOperational = true;
    // https://stackoverflow.com/questions/59625425/understanding-error-capturestacktrace-and-stack-trace-persistance
    Error.captureStackTrace(this, this.consructor);
  }
}

module.exports = AppError;
