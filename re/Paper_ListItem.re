[@bs.module "react-native-paper"]
external listItem : ReasonReact.reactClass = "ListItem";

[@bs.deriving abstract]
type props = {
  title: string,
  [@bs.optional]
  description: string,
  [@bs.optional]
  icon: Paper_Icon.props => ReasonReact.reactElement,
  [@bs.optional]
  avatar: ReasonReact.reactElement,
  [@bs.optional]
  onPress: Rebolt.RNEvent.NativeEvent.t => unit,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: Rebolt.Style.t,
};

let make =
    (
      ~title,
      ~description=?,
      ~icon=?,
      ~avatar=?,
      ~onPress=?,
      ~theme=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=listItem,
    ~props=
      props(
        ~title,
        ~description?,
        ~icon?,
        ~avatar?,
        ~onPress?,
        ~theme?,
        ~style?,
        (),
      ),
    children,
  );
