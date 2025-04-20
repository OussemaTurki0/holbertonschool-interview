// 0-starwars_characters.js

const request = require('request');

function getCharacters(movieId, callback) {
  const url = `https://swapi.dev/api/films/${movieId}/`;

  request(url, async function (error, response, body) {
    if (error) return callback(error);

    try {
      const film = JSON.parse(body);
      const characters = film.characters;
      const names = [];

      for (const charUrl of characters) {
        await new Promise((resolve, reject) => {
          request(charUrl, (err, res, charBody) => {
            if (err) return reject(err);
            const charData = JSON.parse(charBody);
            names.push(charData.name);
            resolve();
          });
        });
      }

      callback(null, names);
    } catch (err) {
      callback(err);
    }
  });
}

module.exports = getCharacters;
