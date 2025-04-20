// main_0.js

const getCharacters = require('./0-starwars_characters.js');

const expected = [
  'Luke Skywalker', 'C-3PO', 'R2-D2', 'Darth Vader',
  'Leia Organa', 'Obi-Wan Kenobi', 'Chewbacca', 'Han Solo',
  'Jabba Desilijic Tiure', 'Wedge Antilles', 'Yoda', 'Palpatine',
  'Boba Fett', 'Lando Calrissian', 'Ackbar', 'Mon Mothma',
  'Arvel Crynyd', 'Wicket Systri Warrick', 'Nien Nunb', 'Bib Fortuna'
];

getCharacters(3, (err, names) => {
  if (err) {
    console.error('Characters not found');
    console.error(err);
    return;
  }

  if (JSON.stringify(names) === JSON.stringify(expected)) {
    console.log('OK');
  } else {
    console.log('Characters not found');
    console.log(names);
  }
});
