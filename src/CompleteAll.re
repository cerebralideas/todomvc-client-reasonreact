[@react.component]
let make = () => {
	let ( _, dispatch ) = React.useContext(Provider.context);

	<button
		onClick={ _ => dispatch((CompleteAll: StateMgmt.action, "", "")) }>
		"Complete All" -> React.string
	</button>
};
