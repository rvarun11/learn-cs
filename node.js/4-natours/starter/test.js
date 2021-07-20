function makeRequest(location) {
  return new Promise((resolve, reject) => {
    console.log(`Making request to ${location}`);
    if (location === 'Google') resolve('Google says hi');
    else reject('We can only talk to Google');
  });
}
async function doWork() {
  try {
    const res = await makeRequest('Facebook');
    console.log('Response received')
    
  }
}