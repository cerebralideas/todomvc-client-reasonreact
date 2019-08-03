# todomvc-client-reasonreact

This is a WIP for learning ReasonML and ReasonReact that will eventually become a full [TodoMVC application](http://todomvc.com/). Yes, [there is this one](https://github.com/reasonml-community/reason-react-example/tree/master/src/todomvc), but I want to write a ReasonML version utilizing my own approach to engineering and architecture.

## Project Progress

NOTE: Each item/step below is a working version of the app.

- [x] Initial: Get a super-basic todo, add-only, name-only, list created [(#2460cc4)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/2460cc4b1869b09ad681bb1389dbee7fc6e21aa4)
- [x] Feature: Create todos with "complete" capability, add `id` and `key`s, convert to `useReducer` and switch [(#5af9884)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/5af9884eba1b14824b474616e5d47226f1e40271)
- [x] Feature: Add delete functionality to todos, move state management to independent module, expand component usage, leverage "pipe first" and "pipe last" (aka "reverse application operator") [(#7672a65)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/7672a65883950eb26f9c647bec8879b28d501f3c)
- [x] Feature: Add client-side routing. This is the recommended way to use ReasonReactRouter. Though, I'm not a fan of how integrated the router is into the React views. [(#6c22a21)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/6c22a21454789adfe8bf5e6c931548a5a9791a79)
- [x] Feature: Add useContext to prevent having to pass state and dispatch around through components [(#d712a5c)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/d712a5c89a1315c866edb0fa732ccfe22ad2beb2)
- [x] Feature: Add "complete all" and "clear completed" functionality [(#b83b72e)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/b83b72e1252492b1464a87154daa1179e67ae81e)
- [x] Feature: Add data persistence using LocalStorage [(#c954486)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/c9544860030ccc358bdbd9c2413c95058bf61c1a)
- [x] Feature: Add official TodoMVC look and feel through official packages [(#c896825)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/c896825c88af59589288dd299802ba44533c9343)
- [x] Fix: Added TodoMVC's CSS and JS to Webpack to avoid needing access to `node_modules` at runtime [(#58a78e2)](https://github.com/cerebralideas/todomvc-client-reasonreact/commit/58a78e272113007cf96b92c4a12ac8478c03ab32)
- [x] Feature: Add "edit" feature to existing todos, clearing input after newly added todo and remove app footer when there are no todos [(master)](https://github.com/cerebralideas/todomvc-client-reasonreact)
- [ ] Feature: Add local Node (`bs-node`) server for initial HTML page
- [ ] Feature: Add React independent client-side routing with `page.js` without hash based routes
- [ ] Feature: Complete full feature parity with TodoMVC: on blur functionality, etc ...
- [ ] Tech: Convert from LocalStorage to IndexedDB (using PouchDB?)

## Run Project

```sh
npm install
npm start
# in another tab
npm run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up `build/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Run Project with Server

To run with the webpack development server run `npm run server` and view in the browser at http://localhost:8000. Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.

Note that any hot reload on a route will fall back to the root (`/`), so `ReasonReact.Router.dangerouslyGetInitialUrl` will likely be needed alongside the `ReasonReact.Router.watchUrl` logic to handle routing correctly on hot reload refreshes or simply opening the app at a URL that is not the root.

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 npm run server`).

## Build for Production

```sh
npm run clean
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version as well as copy `src/index.html` into `build/`. You can then deploy the contents of the `build` directory (`index.html` and `Index.js`).

If you make use of routing (via `ReasonReact.Router` or similar logic) ensure that server-side routing handles your routes or that 404's are directed back to `index.html` (which is how the dev server is set up).

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
