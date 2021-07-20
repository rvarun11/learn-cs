const fs = require('fs');
const server = require('http').createServer();

server.on('request', (req, res) => {
    // Solution 1. Read the file at once and let it loaaddddddd....
    // fs.readFile('test-file.txt', (err, data) => {
    //     if (err) console.log(err);
    //     res.end(data);
    // });
    // Solution 2: basic Streams: can cause backpressure
    // Start the stream
    // const readable = fs.createReadStream('test-file.txt');
    // readable.on('data', (chunk) => {
    //     res.write(chunk);
    // });
    // // once the stream is done, end it
    // readable.on('end', () => {
    //     res.end('DONE!!');
    // });
    // readable.on('error', (err) => {
    //     console.log(err);
    //     res.statusCode = 500;
    //     console.log('File not found');
    // });

    // SOLUTION 3
    const readable = fs.createReadStream('test-file.txt');
    readable.pipe(res);
});

server.listen(8000, '127.0.0.1', () => {
    console.log('Listening....');
});
