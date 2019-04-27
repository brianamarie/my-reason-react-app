/** This module creates all the components we will need in our ToDo
      application:

      * A Task component, that will show a single task
      * An App component, that will glue together the whole application
  */
module Task = {
  [@react.component]
  let make = (~task, ~onDone) => {
    <li
      className=Model.Task.(
        switch (task.status) {
        | Pending => "pending"
        | Done => "done"
        }
      )>
      <button title="done" onClick={_ => onDone(Model.Task.(task.id))} />
      <span> Model.Task.(React.string(task.label)) </span>
    </li>;
  };
};

module ToDo = {
  /** The main component of our application, it initializes ToDo app with
        an initial state and hooks up the reducer and actions with the DOM
        events. */
  [@react.component]
  let make = () => {
    let (state, dispatch) =
      Model.State.(React.useReducer(reducer, initial_state));

    <div>
      <form
        onSubmit={e => {
          ReactEvent.Form.preventDefault(e);
          dispatch(Add_task);
        }}>
        <input
          placeholder="What do you need to do?"
          value=Model.State.(
            switch (state.input) {
            | None => ""
            | Some(str) => str
            }
          )
          onChange={e => {
            let text = ReactEvent.Form.target(e)##value;
            Model.Action.Write(text) |> dispatch;
          }}
        />
        <button type_="submit" title="add" />
      </form>
      <ul>
        Model.State.(
          state.tasks
          |> List.map(task =>
               <Task
                 key=Model.Task.(task.id)
                 task
                 onDone={task_id =>
                   Model.Action.Complete_task(task_id) |> dispatch
                 }
               />
             )
          |> Array.of_list
          |> React.array
        )
      </ul>
    </div>;
  };
};
