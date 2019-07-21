module App = {
	[@react.component]
	let make = () => {
		let ( state, dispatch ) = StateMgmt.initialState |>
			React.useReducer(
				StateMgmt.reducer
			);

		<Router state dispatch />
	};
};

ReactDOMRe.renderToElementWithId(<App />, "index2");
