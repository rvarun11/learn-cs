const Tour = require('../models/tourModel');
const ApiFeatures = require('../utils/apiFeatures');
const AppError = require('../utils/appError');
const catchAsync = require('../utils/catchAsync');

// const filePath = `${__dirname}/../dev-data/data/tours-simple.json`;

// const tours = JSON.parse(fs.readFileSync(filePath));

// lets create param middleware which will check the content

// this is a param middleware
//
// exports.checkId = (req, res, next, val) => {
//   //console.log(req.params);
//   if (req.params.id * 1 > tours.length) {
//     return res.status(404).json({
//       status: 'fail',
//       message: 'Invalid ID',
//     });
//   }
//   next();
// };

// 2.1) Tour Handlers

// now lets remove this redundant try catch block
// we'll pass our catch block inside this function

exports.createTour = catchAsync(async (req, res, next) => {
  // console.log(req.body)
  const newTour = await Tour.create(req.body);
  res.status(201).json({
    status: 'success',
    data: { tour: newTour },
  });
});

// our custom routes
exports.aliasTopTours = (req, res, next) => {
  req.query.limit = '5';
  req.query.sort = '-ratingAverage, price';
  req.query.fields = 'name, price, ratingAverage, summary, difficulty';
  next();
};

exports.getAllTours = catchAsync(async (req, res, next) => {
  // EXECUTE QUERY
  const features = new ApiFeatures(Tour.find(), req.query)
    .filter()
    .sort()
    .limitFields()
    .paginate();
  const tours = await features.query;
  // SEND RESPONSE
  res.status(200).json({
    status: 'success',
    results: tours.length,
    data: { tours },
  });
});

exports.getTour = catchAsync(async (req, res, next) => {
  // this id is coming from /:id in the route
  const tour = await Tour.findById(req.params.id);
  if (!tour) {
    return next(
      new AppError(
        `No Tour with ${req.params.id} found! Please check again`,
        404
      )
    );
  }
  // we can use:
  // Tour.findOne({_id : req.params.id})

  res.status(200).json({
    status: 'success',
    data: { tour },
  });
});

exports.updateTour = catchAsync(async (req, res, next) => {
  // here the 3rd arg is options field. setting new means the updated will be sent to the client
  const tour = await Tour.findByIdAndUpdate(req.params.id, req.body, {
    new: true,
    runValidators: true,
  });
  if (!tour) {
    return next(
      new AppError(
        `No Tour with ${req.params.id} found! Please check again`,
        404
      )
    );
  }
  res.status(200).json({
    status: 'success',
    data: {
      tour,
    },
  });
});

exports.deleteTour = catchAsync(async (req, res, next) => {
  const tour = await Tour.findByIdAndDelete(req.params.id);
  if (!tour) {
    return next(
      new AppError(
        `No Tour with ${req.params.id} found! Please check again`,
        404
      )
    );
  }
  res.status(204).json({
    status: 'success',
    data: null,
  });
});

// BUILDING AN AGGREGATION PIPELINE - allows to build complex queries easily
exports.getTourStats = catchAsync(async (req, res, next) => {
  const stats = await Tour.aggregate([
    { $match: { ratingsAverage: { $gte: 4.5 } } },
    {
      $group: {
        _id: '$difficulty', // this will group by difficulty
        numTours: { $sum: 1 },
        avgRating: { $avg: '$ratingsAverage' },
        avgPrice: { $avg: '$price' },
        minPrice: { $min: '$price' },
        maxPrice: { $max: '$price' },
      },
    },
    // 1 means ascending
    { $sort: { avgPrice: 1 } },
  ]);

  res.status(200).json({ status: 'success', data: { stats } });
});
// business logic
exports.getMonthlyPlans = catchAsync(async (req, res, next) => {
  const year = req.params.year * 1;
  const plan = await Tour.aggregate([
    {
      $unwind: '$startDates',
    },
    {
      $match: {
        startDates: {
          $gte: new Date(`${year}-01-01`),
          $lte: new Date(`${year}-12-31`),
        },
      },
    },
    {
      $group: {
        _id: { $month: '$startDates' },
        numTourStarts: { $sum: 1 },
        tours: { $push: '$name' }, // $push method creates an array
      },
    },
    {
      $addFields: { month: '$_id' },
    }, // this will create a new field called month and store the value of id
    {
      $project: { _id: 0 }, // this will hide the id_ field
    },
    {
      $sort: { numTourStarts: -1 }, //it will sort in descending order based on numTours
    },
    //{ $limit : 6} this will limit the number of fields we want to display
  ]);
  res.status(200).json({ status: 'success', data: { plan } });
});
