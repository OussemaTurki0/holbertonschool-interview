#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie_ID>');
  process.exit(1);
}

const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, async function (error, response, body) {
  if (error) return console.error(error);

  const film = JSON.parse(body);
  const characters = film.characters;

  for (const charUrl of characters) {
    await new Promise((resolve, reject) => {
      request(charUrl, (err, res, charBody) => {
        if (err) return reject(err);
        const charData = JSON.parse(charBody);
        console.log(charData.name);
        resolve();
      });
    });
  }
});
