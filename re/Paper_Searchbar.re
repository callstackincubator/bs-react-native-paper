[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Searchbar";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  placeholder: string,
  [@bs.optional]
  value: string,
  [@bs.optional]
  icon: ReasonReact.reactElement,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: Rebolt.Style.t,
  onChangeText: string => unit,
  [@bs.optional]
  onIconPress: Rebolt.RNEvent.NativeEvent.t => unit,
};

let make =
    (
      ~placeholder=?,
      ~value=?,
      ~icon=?,
      ~theme=?,
      ~style=?,
      ~onChangeText,
      ~onIconPress=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~placeholder?,
        ~value?,
        ~icon?,
        ~theme?,
        ~style?,
        ~onChangeText,
        ~onIconPress?,
        (),
      ),
    children,
  );
