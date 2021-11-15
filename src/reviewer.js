async function readFile(path) {
    const response = await fetch(path);
    return response.text();
}

async function readWords(path) {
    return (await readFile(path)).split('\n');
}

function randomInt(bound) {
    return Math.round(Math.random() * bound);
}

async function generateReview(output) {
    const names = await readWords('names.txt');
    let name1 = names[randomInt(names.length - 1)];
    let name2 = names[randomInt(names.length - 1)];
    const nouns = await readWords('nouns.txt');
    let noun1 = nouns[randomInt((await nouns).length - 1)];
    let noun2 = nouns[randomInt((await nouns).length - 1)];
    output.innerHTML = name1 + ' ' + name2 + ' and the ' + noun1 + ' of ' + noun2;
}
