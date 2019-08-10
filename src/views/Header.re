[@react.component]
let make = () =>
  <header className="header">
    <h1> "todos"->React.string </h1>
    <TodoInput action=Adding />
  </header>;
