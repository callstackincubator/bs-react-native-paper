[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "FABGroup";

[@bs.deriving abstract]
type fabAction = {
  icon: string,
  [@bs.optional]
  label: string,
  [@bs.optional]
  color: string,
  onPress: unit => unit,
};

[@bs.deriving abstract]
type fabState = {
  [@bs.as "open"]
  open_: bool,
};

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  color: string,
  [@bs.as "open"]
  open_: bool,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  icon: ReasonReact.reactElement,
  [@bs.optional]
  style: Rebolt.Style.t,
  [@bs.optional]
  onPress: Rebolt.RNEvent.NativeEvent.t => unit,
  onStateChange: fabState => unit,
  actions: array(fabAction),
};

let make =
    (
      ~color=?,
      ~open_,
      ~theme=?,
      ~icon,
      ~style=?,
      ~onPress=?,
      ~onStateChange,
      ~actions,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~color?,
        ~open_,
        ~icon,
        ~style?,
        ~theme?,
        ~onPress?,
        ~actions,
        ~onStateChange,
        (),
      ),
    children,
  );
