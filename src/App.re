[%bs.raw {|require('todomvc-common/base.css')|}];
[%bs.raw {|require('todomvc-app-css/index.css')|}];
[%bs.raw {|require('todomvc-common/base.js')|}];

module App = {
	[@react.component]
	let make = () => {
		let context =
		StateMgmt.initialState |> React.useReducer(StateMgmt.reducer);

		 <Provider value=context>
		<div className="todoapp">
			<Header />
		     	<Todos />
			" "->React.string
			<AppFooter />
		</div>
		<SiteFooter />
		</Provider>;
	};
};

ReactDOMRe.renderToElementWithId(<App />, "root");
