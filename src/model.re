/** This module defines 3 things for our application:

    * Tasks, with their statuses and how to create them
    * Action, with the possible actions we can use in our application
    * State, representing the state of our application and its reducer
*/
module Task = {
  /** The statuses a Task can be in */
  type status =
    | /** A task that is Pending is a task that hasn't been completed. */
      Pending
    | /** A task that is Done is a task that has been completed. */
      Done;

  /** The type of a task in the ToDo app. */
  type t = {
    /** Every task should have a unique id */
    id: string,
    /** The label to be displayed to the user */
    label: string,
    /** Whether this task has been done or is still pending */
    status,
  };

  /** Task.make("my task") will create a new task with a random id, with
      Pending status, and with "my task" as a label  */
  let make = label => {
    id: Js.Date.now() |> Js.Float.toString,
    label,
    status: Pending,
  };
};

module Action = {
  /** The possible actions of our application */
  type t =
    | /** Write is used to capture user input */
      Write(string)
    | /** Add_task will create a new task using the currently captured user
          input that is already on the state */
      Add_task
    | /** Marks a task as completed */
      Complete_task(string);
};

module State = {
  /** The type of the state of the application. */
  type t = {
    /** A temporary input that holds whatever the user is typing. May be
        empty, represented as None */
    input: option(string),
    /** A list of tasks the user has created */
    tasks: list(Task.t),
  };

  /** The initial state of the application */
  let initial_state = {input: None, tasks: [Task.make("Learn Reason")]};

  /** Our reducer works very similarly to other reducers you may have seen
      before. If receives the current state, and an action, and will compute
      a new state for the application to continue with. */
  let reducer = (state, action) => {
    let new_state =
      switch (action) {
      /* If the action Write has no text at all, we clear up the input */
      | Action.Write("") => {...state, input: None}

      /* If the action Write has text we save it in the state */
      | Action.Write(text) => {...state, input: Some(text)}

      | Action.Add_task =>
        switch (state.input) {
        /* If we have no input in the state, we can't add a task! */
        | None => state

        /* But if we have some input, we can use it as a label */
        | Some(label) => {
            input: None,
            tasks: [Task.make(label), ...state.tasks],
          }
        }

      | Action.Complete_task(id) =>
        let new_tasks =
          state.tasks
          |> List.map(task =>
               switch (id == task.Task.id) {
               | true => {...task, status: Done}
               | _ => task
               }
             );
        {...state, tasks: new_tasks};
      };
    /* We log the state for convenience when developing */
    Js.log(new_state);
    new_state;
  };
};
