[@react.component]
let make = () => {
	let ( _, dispatch ) = React.useContext(Provider.context);
	<button
		onClick={ _ => dispatch(( DeleteCompleted: StateMgmt.action, "", "" )) }>
		"Delete Completed" -> React.string
	</button>
};
