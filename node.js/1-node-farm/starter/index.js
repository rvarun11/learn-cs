// // FILES
// const fs = require('fs');
// // synchronus
// // const textIn = fs.readFileSync('./txt/input.txt', 'utf-8');
// // textOut = `This is what we know about avacode: ${textIn}`;
// // fs.writeFileSync('./txt/output.txt', textOut);

// // asynchronus
// fs.readFile('./txt/start.txt', 'utf-8', (err, data1) => {
//     fs.readFile(`./txt/${data1}.txt`, 'utf-8', (err, data2) => {
//         console.log(data2);
//         fs.readFile(`./txt/append.txt`, 'utf-8', (err, data3) => {
//             console.log(data3);
//             fs.writeFile('./txt/final.txt', `${data2}\n\n${data3}`, 'utf-8', err => {
//                 console.log('Your data has been written');
//             })
//         });
//     });
// });

// console.log(`reading file.....\n`);

//////////////////////////////
// SERVER
// imported from nodejs
const http = require('http');
const fs = require('fs');
// imported from npm
const slugify = require('slugify');
// our module
const replaceTemplate = require(`${__dirname}/modules/replaceTemplate`);

const tempOverview = fs.readFileSync(
    `${__dirname}/templates/template-overview.html`,
    'utf-8'
);
const tempCard = fs.readFileSync(
    `${__dirname}/templates/template-card.html`,
    'utf-8'
);
const tempProduct = fs.readFileSync(
    `${__dirname}/templates/template-product.html`,
    'utf-8'
);
const data = fs.readFileSync(`${__dirname}/dev-data/data.json`, 'utf-8');
const dataObj = JSON.parse(data);

const slugs = dataObj.map((el) => slugify(el.productName, { lower: true }));
console.log(slugs);

const server = http.createServer((req, res) => {
    const baseURL = 'http://' + req.headers.host + '/';
    const myUrl = new URL(req.url, baseURL);
    const pathName = myUrl.pathname;

    // Overview Page
    if (pathName === '/' || pathName === '/overview') {
        res.writeHead(200, { 'Content-type': 'text/html' });
        const cardsHtml = dataObj
            .map((el) => replaceTemplate(tempCard, el))
            .join('');
        const output = tempOverview.replace('{%PRODUCT_CARDS%}', cardsHtml);
        res.end(output);
    }

    // Product Page
    else if (pathName === '/product') {
        res.writeHead(200, { 'Content-type': 'text/html' });
        const product = dataObj[myUrl.searchParams.get('id')];
        const output = replaceTemplate(tempProduct, product);
        res.end(output);

        // API
    } else if (pathName === '/api') {
        res.writeHead(200, { 'Content-type': 'application/json' });
        res.end(data);
    }

    // 404
    else {
        // we should pass the error in our header
        res.writeHead(404);
        res.end(`<h1> 404 </h1>`);
    }
});

server.listen(8080, 'localhost', () => {
    console.log('LISTENING ON PORT 8080');
});
