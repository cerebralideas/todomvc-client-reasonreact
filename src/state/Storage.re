let getTodos = () => {
  let lsValue = Dom.Storage.(localStorage |> getItem("todos"));
  let stringifiedTodos =
    switch (lsValue) {
    | None => "[]"
    | Some(x) => x
    };
  let parseTodos = todo: StateTypes.todo =>
    Json.Decode.{
      id: todo |> field("id", string),
      title: todo |> field("title", string),
      completed: todo |> field("completed", bool),
    };
  stringifiedTodos
  |> Json.parseOrRaise
  |> (json => Json.Decode.(json |> array(parseTodos)) |> Array.to_list);
};
let setTodos = (todos: list(StateTypes.todo)) => {
  let stringifiedTodos =
    todos
    |> Array.of_list
    |> Array.map((todo: StateTypes.todo) =>
         Js.Dict.fromList([
           ("id", Js.Json.string(todo.id)),
           ("title", Js.Json.string(todo.title)),
           ("completed", Js.Json.boolean(todo.completed)),
         ])
       )
    |> Js.Json.objectArray
    |> Js.Json.stringify;

  Dom.Storage.(localStorage |> setItem("todos", stringifiedTodos));
};
