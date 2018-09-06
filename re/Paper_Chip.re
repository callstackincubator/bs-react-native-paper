[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Chip";

[@bs.deriving jsConverter]
type modes = [ | [@bs.as "outlined"] `outlined | [@bs.as "flat"] `flat];

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  mode: string,
  [@bs.optional]
  selected: bool,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  avatar: ReasonReact.reactElement,
  [@bs.optional]
  icon: ReasonReact.reactElement,
  [@bs.optional]
  color: string,
  [@bs.optional]
  style: Rebolt.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  onPress: Rebolt.RNEvent.NativeEvent.t => unit,
  [@bs.optional]
  onClose: Rebolt.RNEvent.NativeEvent.t => unit,
};

let make =
    (
      ~mode=`flat,
      ~selected=?,
      ~disabled=?,
      ~accessibilityLabel=?,
      ~avatar=?,
      ~icon=?,
      ~color=?,
      ~style=?,
      ~theme=?,
      ~onPress=?,
      ~onClose=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~mode=modesToJs(mode),
        ~selected?,
        ~disabled?,
        ~accessibilityLabel?,
        ~avatar?,
        ~icon?,
        ~color?,
        ~style?,
        ~theme?,
        ~onPress?,
        ~onClose?,
        (),
      ),
    children,
  );
