[%bs.raw {|require('todomvc-common/base.css')|}];
[%bs.raw {|require('todomvc-app-css/index.css')|}];
[%bs.raw {|require('todomvc-common/base.js')|}];

module App = {
	[@react.component]
	let make = () => {
		let context = StateMgmt.initialState |>
			React.useReducer( StateMgmt.reducer );

		<Provider value={ context } >
			<AddTodo />
			<Todos />
			" " -> React.string
			<Footer />
		</Provider>
	};
};

ReactDOMRe.renderToElementWithId(<App />, "todoapp");

/**
 * Routing for once we migrate to a server
type func = unit => unit;
[@bs.module] external page: (~path: string=?, ~callback: func=?, unit) => unit = "page"

page(~path="/test", ~callback=() => Js.log("hello"), ());
page();
*/
