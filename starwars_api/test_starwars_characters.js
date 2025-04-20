const assert = require('assert');
const { exec } = require('child_process');

describe('Star Wars Characters Script', function() {
  it('should print the correct characters for movie ID 3', function(done) {
    exec('./0-starwars_characters.js 3', (error, stdout, stderr) => {
      if (error) {
        done(error);
        return;
      }
      if (stderr) {
        done(new Error(stderr));
        return;
      }

      const expectedOutput = [
        'Luke Skywalker',
        'C-3PO',
        'R2-D2',
        'Darth Vader',
        'Leia Organa',
        'Obi-Wan Kenobi',
        'Chewbacca',
        'Han Solo',
        'Jabba Desilijic Tiure',
        'Wedge Antilles',
        'Yoda',
        'Palpatine',
        'Boba Fett',
        'Lando Calrissian',
        'Ackbar',
        'Mon Mothma',
        'Arvel Crynyd',
        'Wicket Systri Warrick',
        'Nien Nunb',
        'Bib Fortuna'
      ];

      const output = stdout.trim().split('\n');
      assert.deepStrictEqual(output, expectedOutput);
      done();
    });
  });
});
