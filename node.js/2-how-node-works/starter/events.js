const EventEmitter = require('events');

class Sales extends EventEmitter {
    constructor() {
        super();
    }
}

const myEmitter = new Sales();

myEmitter.on('new-sale', () => {
    console.log('NEW SALE');
});

myEmitter.on('new-sale', () => {
    console.log('Hello, Varun!');
});

myEmitter.on('new-sale', (stock) => {
    console.log(`Only ${stock} stocks left`);
});

myEmitter.emit('new-sale', 9);
