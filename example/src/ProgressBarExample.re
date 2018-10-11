open BsReactNative;
open Paper;
open Navigation;

module Styles = {
  open Style;

  let container = style([flex(1.0), margin(Pt(10.))]);
};

type state = {progress: float};

type action =
  | ProgressChanged;

let component = ReasonReact.reducerComponent("ProgressBar example");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  initialState: () => {progress: 0.},
  reducer: (action, state) =>
    switch (action) {
    | ProgressChanged =>
      ReasonReact.Update({
        progress: state.progress < 1. ? state.progress +. 0.01 : 0.,
      })
    },
  didMount: self =>
    Js.Global.setInterval(() => self.send(ProgressChanged), 16) |> ignore,
  render: self =>
    <StackNavigator.Screen headerTitle="ProgressBar example" navigation>
      ...{
           () =>
             <View style=Styles.container>
               <Paragraph>
                 {ReasonReact.string("ProgressBar primary color")}
               </Paragraph>
               <ProgressBar progress={Some(self.state.progress)} />
               <Paragraph>
                 {ReasonReact.string("ProgressBar custom color")}
               </Paragraph>
               <ProgressBar
                 progress={Some(self.state.progress)}
                 color="#C62828"
               />
             </View>
         }
    </StackNavigator.Screen>,
};
