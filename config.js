if (process.argv.length == 3) {
    var query = process.argv[2];
    if (query === "libs") {
        console.log(__dirname+'/libs');
    }
}