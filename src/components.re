/** This module creates all the components we will need in our ToDo
      application:

      * A Task component, that will show a single task
      * An App component, that will glue together the whole application
  */
module Task = {
  [@react.component]
  let make = (~task as _, ~onDone as _) => {
    <li> <button title="done" /> </li>;
  };
};

module ToDo = {
  /** The main component of our application, it initializes ToDo app with
        an initial state and hooks up the reducer and actions with the DOM
        events. */
  [@react.component]
  let make = () => {
    <div>
      <form>
        <input placeholder="What do you need to do?" />
        <button type_="submit" title="add" />
      </form>
      <ul />
    </div>;
  };
};
