async function readFile(path) {
    const response = await fetch(path);
    return response.text();
}

async function generateReview(output) {
    output.innerHTML = await readFile('5stars.txt');
}
