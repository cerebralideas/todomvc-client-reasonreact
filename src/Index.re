module App = {
	[@react.component]
	let make = () => {
		let ( state, dispatch ) = React.useReducer(
			StateMgmt.reducer,
			[ StateMgmt.initialTodo ]
		);
		<Todos state dispatch />
	};
};

ReactDOMRe.renderToElementWithId(<App />, "index2");
