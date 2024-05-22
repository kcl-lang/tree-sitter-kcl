# tree-sitter-kcl

[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fkcl-lang%2Ftree-sitter-kcl.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2Fkcl-lang%2Ftree-sitter-kcl?ref=badge_shield)

A tree-sitter grammar for KCL

## Developing

See [here](https://tree-sitter.github.io/tree-sitter/creating-parsers) to install `tree-sitter-cli`

or install npm and run the following command to install

```shell
npm install
```

### Building

Change the grammar in [./grammar.js](./grammar.js) and run the build command

```shell
npm run dev
```

### Testing

Add test suites in [./test/corpus/](./test/corpus/) and run the test command

```shell
npm test
```

## License

[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fkcl-lang%2Ftree-sitter-kcl.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2Fkcl-lang%2Ftree-sitter-kcl?ref=badge_large)
