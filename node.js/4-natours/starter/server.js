const mongoose = require('mongoose');
const dotenv = require('dotenv');

// when they're is an uncaught exception we need to shut down because the node app is in unclean state
// this should be on the top of the program
process.on('uncaughtException', (err) => {
  console.log('Uncaught Exception!! Shutting Down');

  console.log(err.name, err.message);
  process.exit(1);
});

dotenv.config({ path: './config.env' });
const app = require('./app');

//const DB = process.env.DB.replace('<PASSWORD>', process.env.DB_PASSWORD);
mongoose
  .connect(process.env.DB, {
    useNewUrlParser: true,
    useCreateIndex: true,
    useFindAndModify: false,
    useUnifiedTopology: true,
  })
  .then(() => console.log('DB Connected Successfully!!'));

const port = process.env.PORT;
const server = app.listen(port, () => {
  console.log(`App is running on Port ${port}`);
});

process.on('unhandledRejection', (err) => {
  console.log('Unhandled Exception!! Shutting Down');
  console.log(err.name, err.message);

  server.close(() => {
    process.exit(1);
  });
});
