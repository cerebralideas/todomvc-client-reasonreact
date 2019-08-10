[@react.component]
let make = () => {
  let (_, dispatch) = React.useContext(Provider.context);

  <>
    <input
      className="toggle-all"
      type_="checkbox"
      id="toggle-all"
      onChange={_ => dispatch((CompleteAll: StateTypes.action, "", ""))}
    />
    <label htmlFor="toggle-all">
      <span style={ReactDOMRe.Style.make(~position="fixed", ~top="-2em", ())}>
        "Complete All"->React.string
      </span>
    </label>
  </>;
};
