[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Snackbar";

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
  duration: int,
  onDismiss: unit => unit,
  [@bs.optional]
  style: Rebolt.Style.t,
  [@bs.optional]
  action: snackbarAction,
  visible: bool,
};

let make =
    (
      ~theme=?,
      ~duration=?,
      ~onDismiss,
      ~style=?,
      ~action=?,
      ~visible,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(~theme?, ~duration?, ~onDismiss, ~style?, ~action?, ~visible, ()),
    children,
  );
