[@react.component]
let make = (~activeCount: int, ~todoCount: int) => {
	let ( _, dispatch ) = React.useContext(Provider.context);
	activeCount < todoCount ?
		<button className="clear-completed"
			onClick={ _ => dispatch(( DeleteCompleted: StateTypes.action, "", "" )) }>
			"Clear Completed" -> React.string
		</button> :
		<span></span>
};
