let context =
  React.createContext((
    StateMgmt.initialState: StateTypes.state,
    ((_, _, _)) => (): ((StateTypes.action, string, string)) => unit,
  ));

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};

let make = React.Context.provider(context);
