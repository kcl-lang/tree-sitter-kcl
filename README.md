# tree-sitter-kcl

[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fkcl-lang%2Ftree-sitter-kcl.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2Fkcl-lang%2Ftree-sitter-kcl?ref=badge_shield)

A tree-sitter grammar for [KCL](https://www.kcl-lang.io/). The generated parser uses ABI 15, the current tree-sitter ABI.

## Neovim

KCL is already registered with [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter) (`:TSInstall kcl`). This repository is the parser nvim-treesitter installs. Highlight, fold, and injection queries in `queries/` are the reference set checked by `ts_query_ls` in CI. nvim-treesitter keeps its own copy of those queries and does not load them from this repo.

Install the parser from Neovim:

```lua
require("nvim-treesitter").install({ "kcl" }):wait(300000)
```

Or, from the command line: `:TSInstall kcl`.

Neovim does not detect KCL files on its own. The `.k` extension is the builtin `kwt` filetype, so treesitter highlighting does not turn on until the buffer's filetype is `kcl`. [`kcl.nvim`](https://github.com/kcl-lang/kcl.nvim) sets that for `*.k`. Without that plugin:

```lua
vim.filetype.add({
  extension = {
    k = "kcl",
    kcl = "kcl",
  },
})
```

Mapping `.k` overrides `kwt` for every `*.k` buffer.

### Releases

nvim-treesitter treats a parser as stable (tier 1) when versions follow semver and each tag publishes a WASM artifact.

- Patch (`0.2.x`) for fixes that do not change node types.
- Minor (`0.x.0`) for new nodes or patterns. Queries written for the previous minor still match.
- Major for removed or renamed nodes.

After this change is merged, tag the commit so the release workflow uploads `tree-sitter-kcl.wasm`:

```shell
git tag v0.2.0
git push origin v0.2.0
```

Then point nvim-treesitter at that tag. See the pull request for the `parsers.lua` edit. This repository cannot open that pull request.

## Developing

See the [tree-sitter documentation](https://tree-sitter.github.io/tree-sitter/creating-parsers) to install `tree-sitter-cli`, or install npm dependencies:

```shell
npm install
```

### Building

Change the grammar in [./grammar.js](./grammar.js) and regenerate the parser:

```shell
tree-sitter generate
```

### Testing

Add corpus tests in [./test/corpus/](./test/corpus/) or highlight tests in [./test/highlight/](./test/highlight/), then run:

```shell
tree-sitter test
```

Query files are checked against the Neovim capture set in [./.tsqueryrc.json](./.tsqueryrc.json). CI builds the parser and runs `ts_query_ls check`.

### Versioning

Bump every package manifest together with the tree-sitter CLI, then commit the result:

```shell
tree-sitter version 0.2.1
```

## Reference

+ [KCL Grammar](https://www.kcl-lang.io/docs/reference/lang/spec/kcl-spec#grammar)

## License

[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2Fkcl-lang%2Ftree-sitter-kcl.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2Fkcl-lang%2Ftree-sitter-kcl?ref=badge_large)
