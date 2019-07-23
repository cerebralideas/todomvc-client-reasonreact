module App = {
	[@react.component]
	let make = () => {
		let context = StateMgmt.initialState |>
			React.useReducer( StateMgmt.reducer );

		<Provider value={ context } >
			<AddTodo />
			<Todos />
			<Footer />
		</Provider>
	};
};

ReactDOMRe.renderToElementWithId(<App />, "app");
