[@bs.module "react-native-modular"]
external listSection : ReasonReact.reactClass = "ListSection";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: Rebolt.Style.t,
};

let make = (~title=?, ~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=listSection,
    ~props=props(~title?, ~theme?, ()),
    children,
  );
