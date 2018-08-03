[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "HelpText";

[@bs.deriving abstract]
type snackbarAction = {
  label: string,
  onPress: unit => unit,
};

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: Rebolt.Style.t,
  [@bs.optional]
  visible: bool,
  [@bs.as "type"]
  type_: string,
};

let make =
    (~theme=?, ~style=?, ~type_: [ | `error | `info], ~visible, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~theme?,
        ~type_=
          switch (type_) {
          | `error => "error"
          | `info => "info"
          },
        ~style?,
        ~visible,
        (),
      ),
    children,
  );
