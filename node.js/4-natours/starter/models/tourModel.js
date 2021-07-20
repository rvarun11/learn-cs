const mongoose = require('mongoose');
const slugify = require('slugify');

const tourSchema = new mongoose.Schema(
  {
    name: {
      type: String,
      required: [true, 'A Tour must have a name'],
      unique: true,
      trim: true,
    },
    secretTour: {
      type: Boolean,
      default: false,
    },
    duration: {
      type: Number,
      required: [true, 'A Tour must have a duration'],
    },
    maxGroupSize: {
      type: Number,
      required: [true, 'A tour must have a group size'],
    },
    difficulty: {
      type: String,
      required: [true, 'A tour must have a difficulty'],
      enum: {
        values: ['easy', 'medium', 'difficult'],
        message: 'Difficulty can be Easy, Medium, Difficult',
      },
    },
    ratingsAverage: {
      type: Number,
      default: 0.0,
      min: [1, 'Rating must be atleast 1.0'],
      max: [5, 'Rating max must be 5.0'],
    },
    ratingsQuantity: {
      type: Number,
      default: 0,
    },
    price: {
      type: Number,
      required: [true, 'A Tour must have a price'],
    },
    priceDiscount: {
      type: Number,
      validate: {
        // custom validator
        validator: function (val) {
          // this keyword only works when we a new document is created!
          // won't work on update
          return val < this.price;
        },
        message: 'Discount price should be less than the product',
      },
    },
    summary: {
      type: String,
      trim: true,
      required: [true, 'A tour must have a summary'],
    },
    description: {
      type: String,
      trim: true,
    },
    imageCover: {
      type: String,
      required: [true, 'A tour must have a cover'],
    },
    images: [String],
    createdAt: {
      type: Date,
      default: Date.now(),
      select: false,
    },
    startDates: [Date],
    startLocation: {
      // Geo Location
      type: {
        type: String,
        default: 'Point',
        enum: ['Point'],
      },
      coordinates: [Number],
      address: String,
      description: String,
    },
    // EMBEDED DOCUMENT
    locations: [
      {
        // Geo Location
        type: {
          type: String,
          default: 'Point',
          enum: ['Point'],
        },
        coordinates: [Number],
        address: String,
        description: String,
      },
    ],
    guides: Array,
  },
  {
    toJSON: { virtuals: true },
    toObject: { virtuals: true },
  }
);

// these are added to our schema once we get the result from DB..
tourSchema.virtual('durationWeeks').get(function () {
  return this.duration / 7;
});

// DOCUMENT MIDDLEWARE: Mongoose Middleware for Mongo Docs

// runs ONLY before the save() and create()
// called a pre-save hook
tourSchema.pre('save', function (next) {
  //this refers to the currently processed doc
  this.slug = slugify(this.name, { lower: true });
  next();
});
// we can have multiple of these
// tourSchema.pre('save', (next) => {
//   console.log('Will save document next.....!');
//   next();
// });
// // runs after the document is received.
// // it has the document available to it as well
// tourSchema.post('save', (doc, next) => {
//   console.log(doc);
//   next();
// });

// QUERY MIDDLEWARE
// this can allow us to play around with our queries
// for eg we can hide certain types:
// below we are hiding all secret tours
// this will be executed just before find()
//tourSchema.pre('find', function (next) {
// we can use regex to call our middleware with any schema function that starts with find
tourSchema.pre(/^find/, function (next) {
  this.find({ secretTour: { $ne: true } });
  this.start = Date.now();
  next();
});

tourSchema.post(/^find/, function (doc, next) {
  console.log(`Query took: ${this.start - Date.now()} ms`);
  next();
});

//AGGREGATION MIDDLEWARE
tourSchema.pre('aggregate', function (next) {
  this.pipeline().unshift({ $match: { secretTour: { $ne: true } } });
  console.log(this);
  next();
});
const Tour = mongoose.model('Tour', tourSchema);

module.exports = Tour;
