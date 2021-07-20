const mongoose = require('mongoose');
const validator = require('validator');
const bcrypt = require('bcrypt');

const userSchema = new mongoose.Schema({
  name: {
    type: String,
    required: [true, 'A User must have a Name'],
  },
  email: {
    type: String,
    required: [true, 'A User must have an Email'],
    unique: true,
    lowercase: true,
    validate: [validator.isEmail, 'Please enter a valid Email'],
  },
  photo: String,
  password: {
    type: String,
    required: [true, 'Provide Password'],
    minlength: 8,
    select: false,
  },
  passwordConfirm: {
    type: String,
    required: [true, 'Please confirm your password'],
    validate: {
      validator: function (el) {
        // this works only on create and save
        return el === this.password;
      },
      message: 'Passwords are not the same!!',
    },
  },
  passwordChangedAfter: Date,
  role: {
    type: String,
    enum: ['admin', 'user', 'lead-guide', 'guide'],
    default: 'user',
  },
});

userSchema.pre('save', async function (next) {
  // if the user hasn't modified the password then return
  // only run if password was modified
  if (!this.isModified('password')) return next();

  this.password = await bcrypt.hash(this.password, 12);
  // this will remove the confirmPassword field.

  // because we dont want it to persist in our DB
  // we write required in our DB, it means its required for validation but it does not have to be persisted
  this.passwordConfirm = undefined;
  next();
});

userSchema.methods.correctPassword = async (candidatePass, userPass) =>
  await bcrypt.compare(candidatePass, userPass);

// Course -> Section 10, Video 9
userSchema.methods.changedPasswordAfter = function (JWTTimestamp) {
  if (this.passwordChangedAt) {
    const changedTimeStamp = parseInt(
      this.passwordChangedAt.getTime() / 1000,
      10
    );
    return JWTTimestamp < changedTimeStamp;
  }
  // false means not changed which means
  return false;
};

const User = mongoose.model('User', userSchema);
module.exports = User;
