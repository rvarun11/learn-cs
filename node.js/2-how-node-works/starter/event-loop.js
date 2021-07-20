const fs = require('fs');
const crypto = require('crypto');

const start = Date.now();

// default size = 4
process.env.UV_THREADPOOL_SIZE = 1;

// outside the callback fn
setTimeout(() => console.log('Timer 1 Finished'), 0);
setImmediate(() => console.log('Immediate 1 Finished'));

fs.readFile('test-file.txt', () => {
    console.log('IO Finished');
    console.log('--------------------------');

    // inside callback fn
    setTimeout(() => console.log('Timer 1 Finished'), 0);
    setTimeout(() => console.log('Timer 2 Finished'), 4000);
    setImmediate(() => console.log('Immediate 2 Finished'));

    // process ticks run between each phase of the event loop
    // so that's why after Timer callback it runs first..
    process.nextTick(() => console.log('Process Next Tick'));

    crypto.pbkdf2('password', 'salt', 1000, 1024, 'sha512', () => {
        console.log(Date.now() - start, 'Password 1 Encrypted Successfully');
    });

    crypto.pbkdf2('password', 'salt', 1000, 1024, 'sha512', () => {
        console.log(Date.now() - start, 'Password 2 Encrypted Successfully');
    });

    crypto.pbkdf2('password', 'salt', 1000, 1024, 'sha512', () => {
        console.log(Date.now() - start, 'Password 3 Encrypted Successfully');
    });
});

console.log('Top Level Code');
console.log('-------------------------');
