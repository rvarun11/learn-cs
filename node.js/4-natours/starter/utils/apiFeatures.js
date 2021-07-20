class ApiFeatures {
  constructor(query, queryString) {
    this.query = query;
    this.queryString = queryString;
  }

  // BUILD THE QUERY
  // 1A) Filtering
  // We have to create a shallow copy to make changes, otherwise changes will be made on req.query
  // const queryObj = { ...req.query };
  // // our query should not have these special fields
  // const excludedFields = ['sort', 'limit', 'page', 'fields'];
  // excludedFields.forEach((el) => delete queryObj[el]);

  filter() {
    const queryObj = { ...this.queryString };
    const excludedFields = ['sort', 'limit', 'page', 'fields'];
    excludedFields.forEach((el) => delete queryObj[el]);

    // Advanced Filtering using regex
    // this will allow us to use comparison operators
    let str = JSON.stringify(queryObj);
    str = str.replace(/\b(gt|gte|lt|lte)\b/g, (match) => `$${match}`);

    this.query = this.query.find(JSON.parse(str));

    return this;
  }

  sort() {
    if (this.queryString.sort) {
      const sortBy = this.queryString.sort.split(',').join(' ');
      console.log(sortBy);
      this.query = this.query.sort(sortBy);
    } else {
      // by default we are sorted by createdAt
      this.query = this.query.sort('-createdAt');
    }
    return this;
  }

  limitFields() {
    // sensitive fields should always be hidden
    if (this.queryString.fields) {
      const fields = this.queryString.fields.split(',').join(' ');
      this.query = this.query.select(fields);
    } else {
      // by default we are removing
      this.query = this.query.select('-__v');
    }
    return this;
  }

  paginate() {
    // 4) PAGINATION
    const page = this.queryString.page * 1 || 1; // converting to number and default page = 1
    const limit = this.queryString.limit * 1 || 100; // default limit queries = 100
    const skip = (page - 1) * limit;
    // so if page=3&limit=10 ->
    // the we should skip 20 values
    this.query = this.query.skip(skip).limit(limit);

    return this;
  }
}

module.exports = ApiFeatures;
