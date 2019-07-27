[@react.component]
let make = () => {
	let ( _, dispatch ) = React.useContext(Provider.context);
	<button
		onClick={ _ => dispatch(( DeleteCompleted: StateTypes.action, "", "" )) }>
		"Delete Completed" -> React.string
	</button>
};
