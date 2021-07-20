const express = require('express');
const morgan = require('morgan');

const AppError = require('./utils/appError');
const globalErrorHandler = require('./controllers/errorHandler');
const tourRouter = require('./routes/tourRoutes');
const userRouter = require('./routes/userRoutes');

const app = express();

// MIDDLEWARES
// in this file we just define all our middlewares

if (process.env.NODE_ENV === 'dev') {
  app.use(morgan('dev'));
}

app.use(express.json());

app.use((req, res, next) => {
  req.requestTime = new Date().toISOString;
  // console.log(req.requestTime);
  next();
});

// our routes
app.use('/api/v1/tours', tourRouter);
app.use('/api/v1/users', userRouter);

// should be placed at the end to handle requests
app.all('*', (req, res, next) => {
  // // NOTE: when we pass a value in next() of our middleware,
  // // Express automatically assumes it to be an error
  next(new AppError(`Can't find ${req.originalUrl}`, 404));
});

//lets build an error handling middleware
app.use(globalErrorHandler);

module.exports = app;
