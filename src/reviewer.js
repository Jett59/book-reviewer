async function readFile(path) {
    const response = await fetch(path);
    return response.text();
}

async function readWords(path) {
    return (await readFile(path)).split('\n');
}

function randomInt(bound) {
    return Math.floor(Math.random() * bound);
}

async function generateReview(output) {
    const names = await readWords('names.txt');
    let name1 = names[randomInt(names.length - 1)];
    let name2 = names[randomInt(names.length - 1)];
    const nouns = await readWords('nouns.txt');
    let noun1 = nouns[randomInt((await nouns).length - 1)];
    let noun2 = nouns[randomInt((await nouns).length - 1)];
    let stars = randomInt(5) + 1;
    const reviewTerms = await readWords(stars + 'stars.txt');
    let reviewTerm1 = reviewTerms[randomInt(reviewTerms.length - 1)];
    let reviewTerm2 = '';
    do {
        reviewTerm2 = reviewTerms[randomInt(reviewTerms.length - 1)];
    } while (reviewTerm1 == reviewTerm2);
    output.innerHTML = '<h2>' + name1 + ' ' + name2 + ' and the ' + noun1 + ' of ' + noun2 + '<br/>'
        + 'Rated ' + stars + ' star' + (stars != 1 ? 's' : '') + '</h2>'
        + 'Reviews (1):<br/>'
        + reviewTerm1 + ' ' + reviewTerm2;
}
