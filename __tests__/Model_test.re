open Jest;

describe("some test", () => {

  test("passes!", () => {
    Expect.(expect(1) |> toBe(1));
  });

});
