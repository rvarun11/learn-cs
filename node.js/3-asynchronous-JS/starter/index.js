const fs = require('fs');
const superagent = require('superagent');

const readFilePro = (file) => {
  return new Promise((resolve, reject) => {
    fs.readFile(file, (err, data) => {
      if (err) reject('Cannot find file');
      resolve(data);
    });
  });
};

readFilePro(`${__dirname}/dog.txt`).then((data) => {
  console.log(data);
});

// fs.readFile(`${__dirname}/dog.txt`, (err, data) => {
//   superagent
//     .get(`https://dog.ceo/api/breed/${data}/images/random`)
//     .then((res) => console.log(res.body.message))
//     .catch((err) => console.log(err.message));
// });
