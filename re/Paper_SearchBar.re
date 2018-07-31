[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "SearchBar";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  placeholder: string,
  [@bs.optional]
  value: string,
  [@bs.optional]
  icon: ReasonReact.reactElement,
  [@bs.optional]
  theme: Paper_ThemeProvider.theme,
  [@bs.optional]
  style: BsReactNative.Style.t,
  onChangeText: string => unit,
  [@bs.optional]
  onIconPress: BsReactNative.RNEvent.NativeEvent.t => unit,
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
