[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let (state, _) = React.useContext(Provider.context);
  let todoCount = state |> List.length;
  let activeCount =
    state
    |> List.filter((todo: StateTypes.todo) => !todo.completed)
    |> List.length;

  switch (todoCount) {
  | 0 => React.null
  | _ =>
    <footer className="footer">
      <TodoCount activeCount />
      <ul className="filters">
        <li>
          <a
            href="#all"
            className={url.hash == "all" ? "selected" : ""}
            onClick=(_ => ReasonReactRouter.push("#all"))>
            "All"->React.string
          </a>
        </li>
        <li>
          <a
            href="#active"
            className={url.hash == "active" ? "selected" : ""}
            onClick=(_ => ReasonReactRouter.push("#active"))>
            "Active"->React.string
          </a>
        </li>
        <li>
          <a
            href="#completed"
            className={url.hash == "completed" ? "selected" : ""}
            onClick=(_ => ReasonReactRouter.push("#completed"))>
            "Completed"->React.string
          </a>
        </li>
      </ul>
      <DeleteCompleted activeCount todoCount />
    </footer>
  };
};
