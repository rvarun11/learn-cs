const fs = require('fs');
const mongoose = require('mongoose');
const dotenv = require('dotenv');

dotenv.config({ path: '../../config.env' });

const Tour = require('../../models/tourModel');

mongoose
  .connect(process.env.DB, {
    useNewUrlParser: true,
    useCreateIndex: true,
    useFindAndModify: false,
    useUnifiedTopology: true,
  })
  .then(() => console.log('DB Connected Successfully!!'));

// Read JSON file
const tours = JSON.parse(fs.readFileSync(`${__dirname}/tours.json`, 'utf-8'));

// IMPORTING TO COLLECTION
const importDB = async () => {
  try {
    await Tour.create(tours);
    console.log('DATA LOADED');
    process.exit();
  } catch (err) {
    console.log(err);
  }
};

// DELETE FROM COLLECTION
const deleteDB = async () => {
  try {
    await Tour.deleteMany();
    console.log('DATA DELETED');
    process.exit();
  } catch (err) {
    console.log(err);
  }
};

if (process.argv[2] === '--import') {
  importDB();
} else if (process.argv[2] === '--delete') {
  deleteDB();
} else {
  console.log('INCORRECT COMMAND');
  process.exit();
}
