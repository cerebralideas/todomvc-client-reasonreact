let context = React.createContext((
	StateMgmt.initialState: StateMgmt.state,
	((_, _, _)) => (): ((StateMgmt.action, string, string)) => unit
));

let makeProps = (~value, ~children, ()) => {
	"value": value,
	"children": children
};

let make = React.Context.provider(context);
