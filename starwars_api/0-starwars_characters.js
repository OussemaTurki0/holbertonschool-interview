#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2]; // Movie ID passed as the first argument

const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, function (error, response, body) {
  if (error) {
    console.log('Error:', error);
    return;
  }
  
  if (response.statusCode === 200) {
    const filmData = JSON.parse(body);
    const characterUrls = filmData.characters;

    // Loop through the character URLs and fetch each character's details
    characterUrls.forEach((characterUrl) => {
      request(characterUrl, function (err, res, charBody) {
        if (err) {
          console.log('Error:', err);
          return;
        }
        
        if (res.statusCode === 200) {
          const characterData = JSON.parse(charBody);
          console.log(characterData.name);
        }
      });
    });
  }
});
